/*
** prerequis.c for my_str_towordtab in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:44:45 2015 
** Last update Wed Jun 17 17:44:52 2015 
*/

#include "header.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char            *epur_str(char *str)
{
  int           i;
  int           j;
  char          *buf;

  i = 0;
  j = 0;
  if (!str)
    return (0);
  if ((buf = malloc(sizeof(buf) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
        {
          buf[j++] = ' ';
          while (str[i] == ' ' || str[i] == '\t')
            i++;
        }
      buf[j++] = str[i++];
    }
  buf[j] = '\0';
  if (buf[j - 1] == ' ')
    buf[j - 1] = '\0';
  return (buf);
}

int		get_nb_words(char *s)
{
  int   i;
  int   cpt;

  i = 0;
  cpt = 0;
  if (!s)
    return (0);
  while (s[i])
    {
      if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
	  || (s[i] >= '0' && s[i] <= '9'))
	{
	  cpt = cpt + 1;
	  while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
			  || (s[i] >= 'A' && s[i] <= 'Z')
			  || (s[i] >= '0' && s[i] <= '9')))
	    i++;
	}
      i++;
    }
  return (cpt);
}

int		get_nb_char(char *s, int i)
{
  int		cpt;

  cpt = 0;
  while (s[i] && ((s[i] >= 'a' && s[i] <= 'z')
                   || (s[i] >= 'A' && s[i] <= 'Z')
                   || (s[i] >= '0' && s[i] <= '9')))
    {
      cpt++;
      i++;
    }
  return (cpt);
}

char		*get_next_word(char *word, char *str, int i)
{
  int		j;

  j = 0;
  while ((str[i] >= 'a' && str[i] <= 'z')
	 || (str[i] >= 'A' && str[i] <= 'Z')
	 || (str[i] >= '0' && str[i] <= '9'))
    word[j++] = str[i++];
  word[j] = '\0';
  return (word);
}

char		**my_strtowordtab_synthese(char *str)
{
  int		i;
  int		w;
  int		words;
  char		**tab;

  i = -1;
  w = 0;
  str = epur_str(str);
  words = get_nb_words(str);
  tab = malloc(sizeof(char *) * (words + 1));
  while (str && str[++i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
	  || (str[i] >= '0' && str[i] <= '9'))
	{
	  tab[w] = malloc(sizeof(char) * (get_nb_char(str, i) + 1));
	  tab[w] = get_next_word(tab[w], str, i);
	  i = i + get_nb_char(str, i);
	  w++;
	}
    }
  tab[w] = NULL;
  return (tab);
}
