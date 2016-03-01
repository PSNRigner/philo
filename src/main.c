/*
** main.c for  in /home/frasse_l/Projets/PSU_2015_philo
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Mon Feb 29 12:29:19 2016 loic frasse-mathon
** Last update Tue Mar  1 19:53:47 2016 loic frasse-mathon
*/

#include <stdio.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

void	philo(t_arg *arg)
{
  usleep(50000);
  if (arg->id < arg->p - 2)
    sleep_think(arg, arg->id + 1);
  if (arg->id == arg->p - 2)
    {
      sleep_sleep(arg);
      sleep_think(arg, arg->p - 2);
    }
  while (1)
    {
      sleep_eat(arg);
      sleep_sleep(arg);
      sleep_think(arg, arg->p - 2);
    }
}

void	launch(t_arg *arg)
{
  t_arg			*realarg;
  int			i;
  pthread_mutex_t	*sticks;

  if (!(realarg = malloc(sizeof(t_arg) * arg->p))
      || !(sticks = malloc(sizeof(pthread_mutex_t))))
    exit(EXIT_FAILURE);
  i = 0;
  while (i < arg->p)
    {
      realarg[i].p = arg->p;
      realarg[i].e = arg->e;
      realarg[i].id = i;
      realarg[i].sticks = sticks;
      if (pthread_create(&realarg[i].thread, NULL,
			 (void *(*)(void *))philo, &realarg[i]))
	exit(EXIT_FAILURE);
      i++;
    }
  i = 0;
  while (i < arg->p)
    {
      pthread_join(realarg[i].thread, NULL);
      i++;
    }
}

void	arg_error()
{
  printf("%s\n", "Arguments error.");
  exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
  int	opt;
  t_arg	arg;

  arg.p = 0;
  arg.e = 0;
  while ((opt = getopt(ac, av, "e:p:")) != -1)
    {
      if (opt == 'e' && optarg)
	arg.e = atoi(optarg);
      else if (opt == 'p' && optarg)
	arg.p = atoi(optarg);
      else
	arg_error();
    }
  if (arg.e < 1 || arg.p < 3)
    arg_error();
  optind = 1;
  RCFStartup(ac, av);
  launch(&arg);
  RCFCleanup();
  return (0);
}
