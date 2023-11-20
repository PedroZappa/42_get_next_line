set trace-commands on
set logging on

define main
	# target record-full
	display n
	display fd
	display str
	display *str
end

define gnl
	display vault
	display *vault
	display fd
	display substr
	display line
	display *line
	display c_read
end

define getline
	display fd
	display vault
	display *vault
	display substr
	display c_read
	display line
	display *line
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
end

define clearvault
	display i
	display del_i
	display vault
	display *vault
	display rest
	display rest[i]
	display newline
end

define strchr
	display s
	display *s
	display c
end

define strjoin
	display len
	display i
	display str
	display str[i]
end

define memchk
	monitor leak_check full reachable any
end

# Start at get_next_line()
break get_next_line
fs cmd
# break ft_clearvault
# run
# start
# clearvault
# target record-full
# refresh
# gnl
# next
