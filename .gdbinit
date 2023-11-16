define main
	# target record-full
	display n
	display fd
	display str
	display *str
	next
end

define gnl
	display vault
	display *vault
	display fd
	display substr
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
	display restlen
	display vault
	display vault[i]
	display rest
	display rest[i]
	next
end

define strchr
	display s
	display *s
	display c
	next
end

define strjoin
	display len
	display i
	display str
	display str[i]
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
