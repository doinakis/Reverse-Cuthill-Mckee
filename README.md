# Reverse-Cuthill-Mckee


An attempt to parallelize the Reverse Cuthill Mckee algorithm for sparse matrix reordering 


## How to run the code 
  The code runs only for symmetric squeare matrices (adjacency matrices) and computes the Reverse Cuthill Mckee permutation of the input graph. Such graphs and sparse matrices in general can be found [here](https://sparse.tamu.edu/) In order to run the code simply add a matrix market file in the example matrices folder and add the path to the the main file you want to run.
  
## Compare with Matlab 
On the left is the initial matrix,in the middle the matlab RCM and at right the current implementation of RCM.
### G3_circuit   
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_G3_circuit.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_G3_circuit.png" width="250" height="250" /><img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_G3_circuit.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_G3_circuit.png" width="250" height="250" />
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_G3_circuit.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_G3_circuit.png" width="250" height="250" />
### audikw_1
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_audikw_1.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_audikw_1.png" width="250" height="250" /><img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_audikw_1.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_audikw_1.png" width="250" height="250" />
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_audikw_1.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_audikw_1.png" width="250" height="250" />
### dielFilterV3real
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_dielFilterV3real.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_dielFilterV3real.png" width="250" height="250" /><img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_dielFilterV3real.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_dielFilterV3real.png" width="250" height="250" />
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_dielFilterV3real.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_dielFilterV3real.png" width="250" height="250" />
### helm2d03
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_helm2d03.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_helm2d03.png" width="250" height="250" /><img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_helm2d03.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_helm2d03.png" width="250" height="250" />
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_helm2d03.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_helm2d03.png" width="250" height="250" />
### helm3d01
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_helm3d01.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/initial_helm3d01.png" width="250" height="250" /><img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_helm3d01.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/matlab_helm3d01.png" width="250" height="250" />
<img src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_helm3d01.png" alt="" data-canonical-src="https://github.com/doinakis/Reverse-Cuthill-Mckee/blob/master/Diagrams/RCM_helm3d01.png" width="250" height="250" />
