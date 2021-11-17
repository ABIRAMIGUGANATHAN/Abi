import socket
import sys
import json
import os
import linux,subprocess

client.connect(host_ip="192.168.1.101", port=5000)
def client_program(): host = socket.gethostname() 
port = 5000 
 client_socket = socket.socket() 
client_socket.connect((host, port))
request_object = { 
"method": "ping /tmp/client.file",
 "id": "242c41d4-2cc5-4cfb-b815-89e33862e125", 
}
response = client.request(request_object)


message = input(" -> ") 
 while message.lower().strip() != 'bye': client_socket.send(message.encode()) 
 data = client_socket.recv(1024).decode() 


if __name__ == '__main__': 
client_program()
