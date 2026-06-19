*This project has been created as part of the 42 curriculum by aprivalo.*


## Description

Philosophers is a concurrency project based on the classic **dining
philosophers** problem. `N` philosophers share `N` forks around a table and
each one loops **think → eat → sleep**; eating requires **two forks** at once.

The program simulates this with **one thread per philosopher** and **one mutex
per fork**. The whole point is to manage shared resources safely: no two
philosophers may hold the same fork, the simulation must never **deadlock**,
never let a philosopher **starve** (each must eat within `time_to_die` ms), and
must contain **no data races**. A dedicated monitor thread watches for death
and reports it within 10 ms.

## Instructions

### 1. Build

```sh
make
```

Produces `./philo`, compiled with `-Wall -Wextra -Werror` and `-pthread`
(`make clean` / `fclean` / `re` are also available).

### 2. Run

```sh
./philo nb_of_philo time_die time_eat time_sleep (must_eat)
```

All times are in milliseconds. `must_eat` is optional: when set, the simulation
stops once every philosopher has eaten that many times; otherwise it runs until
a philosopher dies.

```sh
./philo 5 800 200 200        # runs forever, nobody dies
./philo 5 800 200 200 7      # stops once all ate 7 times
./philo 1 800 200 200        # a lone philosopher always dies
./philo 4 310 200 100        # timing too tight: someone dies
```

## Resources

- **The Dining Philosophers Problem** — E. W. Dijkstra (1965); overview on
  [Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem).
- **POSIX threads** — `man pthread_create`, `man pthread_mutex_init`,
  `man pthread_join`.
- **Timing** — `man gettimeofday`, `man usleep`.
- **Race detection** — Valgrind tools
  [Memcheck](https://valgrind.org/docs/manual/mc-manual.html) and
  [Helgrind](https://valgrind.org/docs/manual/hg-manual.html).

AI was used as a pair-programming assistant on this project for:
- explain the data structures and the mutex strategy (forks, print, death ... ).
- diagnosing and fixing hards bugs
- verifying `valgrind` Memcheck/Helgrind to confirm no leaks and no data.
