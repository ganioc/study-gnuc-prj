var net = require('net');

var PHRASE = "hello world";

var write = function(socket) {
    console.log("Write to socket");
    socket.write(PHRASE, 'utf8');
}

for (var i = 0; i < 1; i++) {
(function() {
    var socket = net.connect(7000, 'localhost', function() {
        socket.on('data', function(reply) {
            console.log("reply: ", reply.toString('utf-8'));

            if (reply.toString().indexOf(PHRASE) != 0)
                console.error("Problem! '" + reply + "'" + "  '" + PHRASE + "'");
            else{
                setTimeout(()=>{
                    write(socket);
                },2000)
            }
                
        });
        write(socket);
        
    });
})();
}
