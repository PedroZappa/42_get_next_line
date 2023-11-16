define main
	# target record-full
	display n
	display fd
	display str
	display *str
	next
end

define gnl
	display fd
	display buffer
	display line
	display *line
	display c_read
	next
end

define getline
	display fd
	display vault
	display *vault
	display substr
	display *substr
	display c_read
	display line
	display *line
	next
end

define gettillnl
	display vault
	display *vault
	display i
	display len
	display line
	display *line
	display newline
	display *newline
	next
end

define clearvault
	display i
	display j
	display vault
	display vault[i]
	next
end

define strchr
	display s
	display *s
	display c
	display *c
	display i
	display len
	next
end

# Start at get_next_line()
break get_next_line
# run
start
next
# target record-full
# refresh
# gnl
# next
