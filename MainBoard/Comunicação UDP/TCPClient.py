import socket


TCP_IP = '192.168.137.184'
TCP_PORT = 8023
BUFFER_SIZE = 1024
MESSAGE = "close".encode('utf-8')

while True:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((TCP_IP, TCP_PORT))
    s.send(MESSAGE)
    data = s.recv(BUFFER_SIZE)
    s.close()
    print("received data:", data)