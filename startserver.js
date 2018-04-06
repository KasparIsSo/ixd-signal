#!/usr/bin/env node

var WebSocket = require('ws');

var wss = new WebSocket.Server({ port: 8080 });

wss.on('connection', function connection(ws) {
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
  });

  ws.send('something');
});

var serialserver = require('./p5.serialserver');
serialserver.start();
console.log("p5.serialserver is running");
