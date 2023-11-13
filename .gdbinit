# Debug get_next_line()
break get_next_line
run
refresh
display fd
display c_read
display strs
next

define gnl
	display fd
	display buffer
	display strs
end

define get_strs
	display buffer
end

define clear_strs
	display strs
end
