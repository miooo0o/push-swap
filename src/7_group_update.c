
#include "push_swap.h"
#include "../include/push_swap.h"

void	next_target_group(t_group *target)
{
	if (target->name <= target->group_last)
	{
		target->range = target->base_range;
		target->max = target->min - 1;
		target->min = target->max - 11;
		target->name -= 1;
	}
	if (target->name < 1)
		return ;
}