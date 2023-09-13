/* Listens to communication from external program via JSON file */

const fs = require('fs');

const listenForData = setInterval(function() {
  // Search for file of specific name
  fs.readFile('PACK.json', 'utf8', function(e, data) { 
    // If file has no data or doesn't exist, return no value
    if (e || !data) console.log(null);
    // If data is not JSON, return JSON explaining error. Else, return data.
    else {
      try { console.log(data = JSON.parse(data)); } 
      catch { console.log(JSON.parse('{ "ERROR": "Invalid Format" }')); }
      // Delete file 
      fs.unlinkSync('PACK.json');
    }
  });
}, 200);