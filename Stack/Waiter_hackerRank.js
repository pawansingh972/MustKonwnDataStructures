process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function main() {
    var n_temp = readLine().split(' ');
    var n = parseInt(n_temp[0]);
    var q = parseInt(n_temp[1]);
    number = readLine().split(' ');
    number = number.map(Number);
    var a = [];
    var b = [];
    a.push(number);
    var primes = generateFirstNPrimes(q);
    for (var i = 0; i < q; i++) {
        while(a[i].length) {
            var temp = a[i].pop();
            if (temp % primes[i] == 0) {
                if (!b[i]) {
                    b[i] = [];    
                }
                b[i].push(temp);
            } else {
                if (!a[i+1]) {
                    a[i+1] = [];    
                }
                a[i+1].push(temp);
            }
        }
    }
    var temparr;    
    while (b.length) {
        temparr = b.shift();
        while (temparr && temparr.length) {
            console.log(temparr.pop());
        }
    }
    temparr = a.pop();
    while (temparr && temparr.length) {
        console.log(temparr.pop());
    }
}
function generateFirstNPrimes (n) {
    var result = [];
    var i = 3;
    if ( n >= 1 ) {
        result.push(2);
    }
 
    for (var count = 2 ; count <= n ;  ) {
        for ( var c = 2 ; c <= i - 1 ; c++ ) {
            if ( i % c == 0 )
                break;
        }
        if ( c == i ) {
            result.push(i);
            count++;
        }
        i++;
    }
    
    return result;
}
