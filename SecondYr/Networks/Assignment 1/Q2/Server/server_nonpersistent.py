import socket

host = ""
port = 8080

while(True):
	# Create socket and bind it to a port
	s = socket.socket()
	s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)

	s.bind((host, port))
	# Listen for client socket
	s.listen(5)
	conn, addr = s.accept()


	filename = conn.recv(1024)
	print (filename)
	# If client wants to exit
	if filename == 'exit!':
		break

	#Filename exists, send it
	try:
		fp = open(filename,'rb')
		conn.send("Found")

		para = fp.read(1024)

		while (para):
			length = len(para)
			conn.send(str(length))

			conn.send(para)
			print('Sent ',repr(para))

			para = fp.read(1024)

		fp.close()

	#Filename does not exist
	except:
		conn.send('Not Found')
		print ("Not Found")

print('Done sending')
conn.send('Thank you for connecting')
conn.close()
