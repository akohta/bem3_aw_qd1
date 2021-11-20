# bem3_aw_qd1
This is the three-dimensional acoustic wave scattering analysis program for one-dimensional periodic arrangement objects irradiated by a plane wave. 
The radiation force acting on the object can be analyzed. 
This is based on boundary element method, the own developed numerical solution is used. 
Intel Math Kernel Library and libpng are required. 
Gmsh is used for create a mesh data of object. 
The calculation program of quasi-periodic Green's function "d3_qpgf_d1" is used.  

![analysis model](model_qpbc1.png "analysis model (model_qpbc1.png)")  


## Usage of example code  

1. type 'make' command to compile.  
   The executable aw_d3qd1_bv_solver, example1.out, example2.out, example3.out are created. 
   The aw_d3qd1_bv_solver is the main solver of boundary integral equations.
   The example1.out is the executable of source code example1.c, it shows a simplest example using "bem3_aw_qd1". 
   The example2.out is the executable of source code example2.c, it shows a example of sound pressure intensity analysis. 
   The example3.out is the executable of source code example3.c, it shows a example of outputting the instantaneous value of sound pressure as an image.  
   
2. type './aw_d3qd1_bv_solver' with arguments of plane wave datafile name, periodicity datafile name, medium datafile name, mesh datafile name, output datafile name, rotation and translation settings (optional).  
   For example, './aw_d3qd1_bv_solver pw.txt periodicity_data.txt medium.txt sphere_m1.msh ex.dat'. 
   The pw.txt is the sample of incident field datafile, a plane wave is defined in it. 
   The periodicity_data.txt is the sample of periodicity datafile, periodic boundary condition and lattice constant are defined in it. 
   The medium.txt is the sample of medium datafile, one medium is defined in it. The domain number is assinged to the medium from 1 in order. 
   The sphere_m1.msh is the sample of mesh datafile, it is a sphere object. 
   It was created by Gmsh geometry file sphere_m1.geo in the mesh_sample folder.
   The sphere_m1_image.png is the visualization result of the sphere_m1.msh.  
   
3. type './example1.out' with an argument of datafile name output by aw_d3qd1_bv_solver.  
   For example, './example1.out ex.dat'. This executable calculates sound pressure, radiaton force and torque. 
   
4. type './example2.out' with an argument of datafile name output by aw_d3qd1_bv_solver.  
   For example, './example2.out ex.dat'. This executable calculates sound pressure intensity distributions, outputs them to text files. 
   The I_example2.png is the visualization result of intensity distributions, created by Gnuplot script gscritp_example2.plt
   (using ImageMagick to convert eps to png).  
   
5. type './example3.out' with an argument of datafile name output by aw_d3qd1_bv_solver.  
   For example, './example3.out ex.dat'. This executable calculates instantaneous value of the sound pressure, outputs them to png image files. 
   The image files are output to the folder which has a name adding "images" to the datafile name specified in the argument (file-extension is excluded). 
   Each image file has a name that indicates the cross section, field component, and number of time steps (ex. xz_p_014.png). 
   The color bar is output as color_bar.png in the same folder. 
   The range of color bar in each cross section is output to the info.txt file (ex. xy_info.txt for z=0 plane). 
   The xz_p.gif, yz_p.gif and xy_p.gif are animated gifs that concatenate the png files created by using the shell script gif_animation.sh.  
   
Please see d3qd1_src/bem3_aw_qd1.h for detail of functions.
The main parts of the code are parallelized by using OpenMP. 
The number of threads is controlled by the environment variable OMP_NUM_THREADS.  

![mesh image 0](sphere_m1_image.png "mesh image of the unit object (sphere_m1_image.png)") 
![intensity distributions 0](I_example2.png "intensity distributions (I_example2.png)")  
![xz_p.gif](xz_p.gif "instantaneous value of the p on y=0 plane (xz_p.gif)")![yz_p.gif](yz_p.gif "instantaneous value of the p on x=0 plane (yz_p.gif)")  
![xy_p.gif](xy_p.gif "instantaneous value of the p on z=0 plane (xy_p.gif)")  


## Analysis sample 2 (in the folder analysis_sample2) 

This is the analysis result of plane wave scattering by three spheres arranged in y-axis direction.

![mesh image 2](analysis_sample2/sphere_m3_image.png "mesh image of the unit object (analysis_sample2/sphere_m3_image.png)") 
![intensity distributions 2](analysis_sample2/I_example2.png "intensity distributions (analysis_sample2/I_example2.png)")  
![xz_p.gif 2](analysis_sample2/xz_p.gif "instantaneous value of the p on y=0 plane (analysis_sample2/xz_p.gif)")![yz_p.gif 2](analysis_sample2/yz_p.gif "instantaneous value of the p on x=0 plane (analysis_sample2/yz_p.gif)")  
![xy_p.gif 2](analysis_sample2/xy_p.gif "instantaneous value of the p on z=0 plane (analysis_sample2/xy_p.gif)")  


## Verification  

The verification results are in the folder verification. 
The analysis result of arrangement of 7 spheres using "aw_msp_ivf" (in the folder aw_msp_ivf_result) 
and the analysis result of periodic arrangement of spheres are shown. 


## About mesh file

This code can use quadrangular (bi-linear) and triangular (linear triangular) elements. 
I recommend using quadrangular element for reduce required memory. 
The samples of mesh data are in the folder mesh_sample. 
The file with extension .geo is the Gmsh geometry file. 
The file with extension .msh is the mesh file created by using Gmsh geometry file. 
These mesh files are created by the command 'gmsh -2 -tol 1.0e-15 xxxx.geo' in command line (xxxx.geo is a geometry file). 
The domain number (Physical Surface) 99 is assigned to the open region in Gmsh geometry file, because Gmsh can't use the number 0 (assigned to open region in the code). 
Please refer to the manual of Gmsh for detail of geometry file.  


## Reference  

1. Intel Math Kernel Library [MKL](https://software.intel.com/mkl)  
2. The official PNG reference library [libpng](http://www.libpng.org/pub/png/libpng.html)  
3. Three-dimensional mesh generator [Gmsh](https://gmsh.info/)
4. The command-line driven graphing utility [gnuplot](http://www.gnuplot.info/)  
5. The utilities for manipulating images [ImageMagick](https://imagemagick.org/)  
6. The calculation program of quasi-periodic Green's function [d3_qpgf_d1](https://github.com/akohta/d3_qpgf_d1/)
7. The acoustic wave scattering analysis program [aw_msp_ivf](https://github.com/akohta/aw_msp_ivf/)  

