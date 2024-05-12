set trace-commands on
set logging enabled on

define main
	# target record-full
	display *line
	display fd
	display n_fds
	display fd[i]
	display n
	display i
end

define gnl
	display vault
	display *vault
	display fd
	display line
	display *line
end

define getline
	display fd
	display bytes_read
	display buffer
	display *buffer
end

define gettillnl
	display vault
	display vault[i]
	display i
	display line
	display line[i]
end

define getrest
	display i
	display rest_i
	display vault
	display vault[i]
	display rest
	display rest[rest_i]
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
	display s1
	display s2
	display str
	display str[i]
end

define vgdb
	target remote | vgdb
end

define mchk
	monitor leak_check full reachable any
end

# Start at get_next_line()
break get_next_line
fs cmd
