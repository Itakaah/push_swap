#include "stack.h"

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench, float disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b, bench);
	else if (disorder < 0.5 && a->size <= 50)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}
