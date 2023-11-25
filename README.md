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

`get_next_line` is a [42 Common Core](https://github.com/PedroZappa/42_CommonCore) project that delves into how `static variables` and `file descriptors` work. It is a challenge on `memory allocation`. It returns the contents of a line per function call from a given `fd`, until the end of the file is reached. `get_next_line` must be implemented so that it handles any `BUFFER_SIZE` defined at compile time. The bonus challenge is simple: the implementation must be able to handle multiple file descriptors at any time. Each function call should be able to read from different `fd`s without loosing track of partial lines read into its `static` buffer. 

---

# Usage :checkered_flag:

Two distinct implementation can be found in this repository: the one on `srcll` implements `Linked Lists` without the bonus; while the other on `srcb` uses `Arrays` and meets the bonus requirements. 

## srcll : `get_next_line` with `Linked Lists` 🔗

