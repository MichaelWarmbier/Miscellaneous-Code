/* Small function add a small range of time to a time string */

militaryTime = true;

function addTimeToString(time, offset) {
    if (offset > 60) offset = 60;

    const TOD = time.includes('AM');
    const hours = parseInt(time[0] + time[1]);
    const minutes = parseInt(time[3] + time[4]);

    let newMinutes = ((minutes + offset) % 60).toString();
    let newHours = (hours + Math.floor((minutes + offset) / 60)).toString();
  
    if (militaryTime && parseInt(newHours) >= 24) newHours = (parseInt(newHours) % 24).toString();
    if (!militaryTime && parseInt(newHours) > 12) newHours = (parseInt(newHours) % 12).toString();
    if (!militaryTime && parseInt(newHours) >= 12) {
      if (TOD)   time = time.replace('AM', 'PM');
      else       time = time.replace('PM', 'AM');
    }

    if (newMinutes.length == 1) newMinutes = newMinutes.replace(/^/, '0');
    if (newHours.length == 1) newHours = newHours.replace(/^/, '0');

    time = time.replace(minutes.toString(), newMinutes);
    time = time.replace(hours.toString(), newHours);
  
    return time;

}

console.log(addTimeToString('23:30', 35));