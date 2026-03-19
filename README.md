*This project has been created as part of the 42 curriculum by <login1>.*

# Description

This project is a solution to the classic "Dining Philosophers" problem, implemented as part of the 42 school curriculum. The goal is to simulate the behavior of philosophers who alternately think, eat, and sleep, while sharing forks and avoiding deadlocks and starvation. The project demonstrates concepts in concurrent programming, synchronization, and resource sharing using threads and mutexes in C.

# Instructions

## Compilation

To compile the project, run the following command in the root directory:

```
make
```

This will build the executable using the provided Makefile.

## Execution

After compilation, run the program with the following command:

```
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `<number_of_philosophers>`: Number of philosophers and forks
- `<time_to_die>`: Time (in ms) before a philosopher dies if they don't start eating
- `<time_to_eat>`: Time (in ms) it takes for a philosopher to eat
- `<time_to_sleep>`: Time (in ms) a philosopher spends sleeping
- `[number_of_times_each_philosopher_must_eat]`: (Optional) Simulation ends when each philosopher has eaten this many times

Example:

```
./philo 5 800 200 200
```

# Resources

- [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- 42 School Subject PDF