# Multiple Traveling Salesman Problem (mTSP) - Comparative Study of Metaheuristics

## Overview

This project is a comparative study of various metaheuristics applied to the Multiple Traveling Salesman Problem (mTSP). The mTSP is a generalization of the well-known Traveling Salesman Problem (TSP), where multiple salesmen must visit a set of cities, minimizing the total distance traveled by all salesmen. This work is based on the paper [**"Estudo Comparativo de Metaheurísticas Aplicadas ao Problema do Caixeiro Viajante Múltiplo"**](https://www.researchgate.net/publication/364811163_ESTUDO_COMPARATIVO_DE_METAHEURISTICAS_APLICADAS_AO_PROBLEMA_DO_CAIXEIRO_VIAJANTE_MULTIPLO), which provides a detailed analysis of different approaches to solving the mTSP.

## Metaheuristics Implemented

The following heuristics were implemented to solve the mTSP:

- **Greedy Heuristic**: A simple greedy algorithm that selects the closest unvisited city for each salesman.
- **Nearest Neighbor Heuristic**: This heuristic picks the nearest city to the current city for each salesman.
- **Random Heuristic**: A heuristic that assigns cities to salesmen randomly, serving as a baseline.

## Getting Started

### Prerequisites

To build and run this project, you will need:

- g++
- make

### Build Instructions

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/mateushonorato/mTSP_Project.git
   cd mTSP_Project
   ```

2. **Build the Project**:

   ```bash
   make
   ```

   If you run into any problems, try running:

   ```bash
   make clean
   ```

3. **Run the Executable**:
   ```bash
   ./bin/mtsp -i <instance_file> -h <heuristic> -n <num_salesmen>
   ```

### Usage

The program reads problem instances from the `instances/` directory and outputs the results to the `results/` directory. The results include the total distance traveled by all salesmen for the given heuristic.

### Example

To run this program, you must specify the instance name, the heuristic and the number of salesmen:

```bash
./bin/mtsp -i <instance_file> -h <heuristic> -n <num_salesmen>
```

You can also use optional arguments to run all instances, all heuristics, or turn on verbose output:

```bash
Usage: ./bin/mtsp -i <instance_file> -h <heuristic> -n <num_salesmen>
Options:
  --instance, -i: Instance file
  --heuristic, -h: Heuristic to be used
  --num-salesmen, -n: Number of salesmen
  --all-heuristics, -ah: Run all heuristics
  --all-instances, -ai: Run all instances
  --verbose, -v: Print detailed output
```

## Results

The results of running the different heuristics on various instances are stored in the `results/` directory. Each file contains detailed output for each instance, including the routes taken by each salesman and the total distance.

## Acknowledgments

- Special thanks to the authors of the paper [**"Estudo Comparativo de Metaheurísticas Aplicadas ao Problema do Caixeiro Viajante Múltiplo"**](https://www.researchgate.net/publication/364811163_ESTUDO_COMPARATIVO_DE_METAHEURISTICAS_APLICADAS_AO_PROBLEMA_DO_CAIXEIRO_VIAJANTE_MULTIPLO) for providing a solid foundation for this project.
- Thanks to the developers of TSPLIB 95 for the provided instances
- Thanks to Federal University of Ouro Preto (UFOP) for the resources and support provided.
