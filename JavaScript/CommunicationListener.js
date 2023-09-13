/* Work in Progress Library */

const LAN = {
  fs: require('fs'),
  Ports: [],

  createPort(portName, Type) {
    if (this.getPort(portName)) return false;
    if (Type != 'Sending' && Type != 'Receiving') Type = 'Sending';
    this.fs.writeFile(`${portName}.json`, '{}', function(err) { if (err) return false; });
    this.Ports.push({ Name: portName, Type: Type, Status: 0 })
    return true;
  },

  async listenForData(portName, listenTimeMS) {

    const targetPort = this.getPort(portName);
    const attemptsToMake = Math.floor(listenTimeMS / 100);
    let totalAttempts = 0;
  
    return new Promise((resolve, reject) => {

      if (!targetPort || targetPort.Type != 'Receiving') resolve({ERROR: 'Port invalid'});
      targetPort.Status = 1;
      
      const PingInterval = setInterval (() => {
        totalAttempts++;
        this.fs.readFile(`${portName}.json`, 'utf8', function(err, data) {
  
          if (totalAttempts >= attemptsToMake) { 
            clearInterval(PingInterval); 
            targetPort.Status = 0; 
            resolve({ERROR: 'Response too slow'});
          }
            
          else if (!err && data) {
            try { data = JSON.parse(data); }
            catch { clearInterval(PingInterval); targetPort.Status = 0; resolve({ERROR: 'Invalid format'}); }
            resolve(data);
          }
            
        })
      }, 100);
    })
  },

  sendData(portName, data) {
    for (port of this.Ports) if (port.Name === portName) port.Status = 1;
    this.fs.readFile(`${portName}.json`, 'utf8', function(err, _) { if (err) return false; } )
    this.fs.writeFile(`${portName}.json`, JSON.stringify(data), function(err) { if (err) return false; return true; })
  },

  displayPorts() { console.log(this.Ports); },
  getPort(portName) { for (port of this.Ports) if (portName === port.Name) return port; return null; },
  clearPorts() { for (port of this.Ports) this.fs.unlinkSync(`${port.Name}.json`); Ports = [] }
};