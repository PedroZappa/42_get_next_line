define main
	display n
	display max_n
	display fd
	display str
	display *str
	next
end

define gnl
	display fd
	display c_read
	display strs
	display *strs
	display line
	display *line
	next
end

define getline
	display fd
	display buffer
	display *strs
	display *c_read
	next
end

define storestr
	display i
	display buffer
	display *strs
	display last_str
	display *new_str
	next
end

define get_strs
	display strs->str
	display *line
	next
end

define clear_strs
	display i
	display j
	display strs
	display **strs
	display last_n->str
	display last_n->str[i]
	display cleared->str
	display cleared
	next
end

# Start at get_next_line()
break get_next_line
run
# target record-full
refresh
gnl
next

# Start at ft_storestr()
# break ft_storestr
# run
# refresh
# storestr
# next

# Start at ft_get_strs()
# break ft_get_strs
# run
# refresh
# get_strs
# next

# Start at ft_clear_strs()
# break ft_clear_strs
# run
# refresh
# clear_strs
# next
