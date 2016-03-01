/*
** philo.h for  in /home/frasse_l/Projets/PSU_2015_philo
** 
** Made by loic frasse-mathon
** Login   <frasse_l@epitech.net>
** 
** Started on  Tue Mar  1 17:24:08 2016 loic frasse-mathon
** Last update Tue Mar  1 19:54:26 2016 loic frasse-mathon
*/

#ifndef PHILO_H_
# define PHILO_H_

# define UNITY_SLEEP	10000

typedef struct		s_arg
{
  int			p;
  int			e;
  int			id;
  pthread_t		thread;
  pthread_mutex_t	*sticks;
}			t_arg;

void	sleep_sleep(t_arg *);
void	sleep_eat(t_arg *);
void	sleep_think(t_arg *, int);

#endif
