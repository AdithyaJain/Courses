import socket                   

host = ""
port = 8080 

while(True):
	# Create socket and bind it to a port
	s = socket.socket()
	# Connect to server socket
	s.connect((host, port))


	filename = raw_input("Enter file name: ")
	# Send server required file name
	s.send(filename)
	# If client wants to exit
	if filename == 'exit!':
		break

# Check if file exists on server end
	is_exist = s.recv(1024)
	print (is_exist)

	if is_exist == "Found":
		# Open file and write into it
		with open(filename, 'wb') as f:
			length = 1024
			while length >= 1024:
				length = int(s.recv(4))
				print (length)

				buff = s.recv(length)
				print('buffer:')
				print(buff)

				f.write(buff)

		f.close()
		print('Successfully got the file')

	else:
		continue


s.close()
print('connection closed')
