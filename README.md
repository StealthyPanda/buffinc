<p align="center">
  <a href="https://github.com/StealthyPanda/buffinc" rel="noopener">
 <img width=150px height=150px src="./docs/logo.png" alt="Project logo"></a>
</p>

<h3 align="center">Tachyon</h3>

<div align="center">

  [![Status](https://img.shields.io/badge/status-active-success.svg)]() 
  <!-- [![GitHub Issues](https://img.shields.io/github/issues/stealthypanda/buffinc.svg)](https://img.shields.io/github/issues/stealthypanda/buffinc.svg)
  [![GitHub Pull Requests](https://img.shields.io/github/issues-pr/stealthypanda/buffinc.svg)](https://img.shields.io/github/issues-pr/stealthypanda/buffinc.svg) -->
  [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)
  <!-- ![GitHub release (latest by date)](https://img.shields.io/github/v/release/stealthypanda/buffinc) -->

</div>

---

<p align="center"> A C++ render engine. WIP. Powered by <a href = "https://github.com/stealthypanda/hermes">hermes</a>.
    <br> 
</p>

<!-- ## Table of Contents
- [Table of Contents](#table-of-contents)
- [About ](#about-)
- [Authors ](#authors-) -->




## About <a name = "about"></a>
This is meant to be a fast render engine, written from scratch mainly in C++. It uses no external libraries, and in its final stage, will be a complete rendering pipeline with no external dependencies and completely self contained from generating assets to the final render. The project is still in a very early phase. 

<div align = "center">

  ![First Render in tachyon](./docs/firstrender.gif)

  *first ever render in tachyon*
  
</div>

This project uses the <a href = "https://github.com/stealthypanda/hermes">hermes build system</a>.
<!-- ## Getting Started <a name = "getting_started"></a> -->
<!-- ### Prerequisites
This library is self contained, and optionally uses matplotlib for plotting graphs.

### Installing
This library can be installed from pypi using pip:


```
$ pip install buffinc
```

To make sure everything installed properly, import the main and only module in python:

```
from quantum import * -->

<!-- ## 🔧 Running the tests <a name = "tests"></a>
Explain how to run the automated tests for this system.

### Break down into end to end tests
Explain what these tests test and why

```
Give an example
```

### And coding style tests
Explain what these tests test and why

```
Give an example
``` -->
<!-- 
## Usage <a name="usage"></a>
*Go through example.ipynb for a comprehensive guide on using this library*

Sample workflow:

```
entangler = qprogram(
    nqbits = 2,
    name = "Entangler"
)
entangler.addgates(0, [HGATE, CNOT0])
entangler.compile()
```
Compiler result:
```
Compiling Entangler...

Entangler
q0(0) ⮕  -----[ h ]--⌈ c0 c0 ⌉-------
q1(0) ⮕  ------------⌊ c0 c0 ⌋-------


Compilation of Entangler complete!
```

and to run the program:

```
entangler.run(graph = True)
```
![graph](./docs/graph.png)

and view bloch spheres for qubits:
```
plotbloch(HGATE * [0, 1])
```
![bloch](./docs/bloch.png) -->

<!-- ## 🚀 Deployment <a name = "deployment"></a>
Add additional notes about how to deploy this on a live system.

## ⛏️ Built Using <a name = "built_using"></a>
- [MongoDB](https://www.mongodb.com/) - Database
- [Express](https://expressjs.com/) - Server Framework
- [VueJs](https://vuejs.org/) - Web Framework
- [NodeJs](https://nodejs.org/en/) - Server Environment -->

## Authors <a name = "authors"></a>
[![Foo](https://img.shields.io/badge/Made_with_❤️_by-@stealthypanda🐼-orange?style=for-the-badge&logo=python&link=)](https://sites.google.com/iitj.ac.in/stealthypanda/home)


<!-- 
See also the list of [contributors](https://github.com/kylelobo/The-Documentation-Compendium/contributors) who participated in this project.

## 🎉 Acknowledgements <a name = "acknowledgement"></a>
- Hat tip to anyone whose code was used
- Inspiration
- References -->
