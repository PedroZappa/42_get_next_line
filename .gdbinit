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
	display line
	display *line
	display input
	next
end

define getline
	display c_read
	display fd
	display input
	display line
	display *line
	next
end

define gettillnl
	display i
	display line
	display *line
	display input
	display *input
	next
end

define getrest
	display i
	display j
	display input
	display input[i]
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

