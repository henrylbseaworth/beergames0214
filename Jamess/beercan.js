//usage: node beercan.js file key
var fs = require("fs");

var args = process.argv.slice(1);

if ( args.length > 2 ) {

    var fname   = args[1];
    var key     = args[2];
    var fdata   = fs.readFileSync(fname, 'utf-8');
    var farr    = fdata.split(key);

    for ( var i = 0; i < farr.length; i++ ) {

        if ( i == farr.length - 1 ) process.stdout.write(farr[i]);
        else process.stdout.write(farr[i] + key + "("+String(i+1)+")");

    }

} else {
     console.error("Not enough arguments.");
     process.exit(1);
}
