/*
** sleep.c for  in /home/frasse_l/Projets/PSU_2015_philo
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Tue Mar  1 19:16:48 2016 loic frasse-mathon
** Last update Tue Mar  1 19:54:02 2016 loic frasse-mathon
*/
#include <stdlib.h>
#include "extern.h"
#include "philo.h"

void	sleep_sleep(t_arg *arg)
{
  lphilo_sleep();
  usleep(UNITY_SLEEP);
  (void)arg;
}

void	sleep_eat(t_arg *arg)
{
  lphilo_eat();
  arg->e--;
  if (arg->id == arg->p - 1 && arg->e == 0)
    exit(0);
  usleep(UNITY_SLEEP);
}

void	sleep_think(t_arg *arg, int n)
{
  lphilo_think();
  usleep(UNITY_SLEEP * n);
  (void)arg;
}
