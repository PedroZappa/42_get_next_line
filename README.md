<a name="readme-top"></a>
<div align="center">

# get_next_line

> Because reading a line from a `fd` is way too tedious. 😪

<p>
    <img src="https://img.shields.io/badge/score-...%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/PedroZappa/get_next_line?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/PedroZappa/get_next_line?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/PedroZappa/get_next_line?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/PedroZappa/get_next_line?style=for-the-badge" />
</p>

___

<h3>Table o'Contents</h3>
<p>
    ~
    <a href="#about-pushpin">About</a> ~
    <a href="#usage-scroll">Usage</a> ~
    <a href="#implementation-exclamation">Implementation</a> ~
    <a href="#structure-bar_chart">Structure</a> ~
    <a href="#license">License</a> ~
</p>
<div/>

# About :pushpin:

`get_next_line` is a [42 Common Core](https://github.com/PedroZappa/42_CommonCore) project that delves into how `static variables` and `file descriptors` work. It is a challenge on `memory allocation`. 


---

# Usage :checkered_flag:

0. Clone repository & enter directory:

```sh
	git clone https://github.com/PedroZappa/get_next_line.git zedro-gnl
	cd zedro-gnl
```

Two distinct implementation can be found in this repository: the one on `srcll` implements `Linked Lists` without the bonus; while the other on `srcb` uses `Arrays` and meets both mandatory and bonus requirements. 

___

1. Compile mandatory `get_next_line` with `Arrays` 🗂:

```sh
make
```

2. Compile bonus `get_next_line` with `Arrays` 🗂:

```sh
make bonus
```

3. Compile mandatory `get_next_line` with `Linked Lists` 🔗:

```sh
make extrall
```

___

# Implementation :scroll:

## Mandatory 

`get_next_line` must:
- Return the contents of a line per function call read from a given `file descriptor`, until the end of the file is reached. 
- it must be implemented so that it handles any `BUFFER_SIZE` defined at compile time. 

## Bonus

- Must use only one `static` variable.
- The function must be able to handle multiple file descriptors appropriately.
- Each function call should be able to read from different `fd` without loosing track of partial lines read into its `static` buffer. 

___
