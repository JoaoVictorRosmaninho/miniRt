#ifndef TRANSLATION_H
# define TRANSLATION_H

typedef t_matrix t_point2;
typedef t_matrix t_vector2;

t_matrix* translation_new(double x, double y, double z, t_coliseu*  coliseu);
t_matrix* scale_new(double x, double y, double z, t_coliseu*  coliseu);

t_point2* translation_transform(t_matrix* translation, t_point2* point, t_coliseu* coliseu);

#endif