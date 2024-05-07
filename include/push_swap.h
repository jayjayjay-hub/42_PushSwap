/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtakahas <jtakahas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:09:38 by jay               #+#    #+#             */
/*   Updated: 2024/05/07 15:58:28 by jtakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

# define RA_RB 1
# define RRA_RRB 2
# define RA_RRB 3
# define RRA_RB 4

typedef struct s_command
{
	int		all;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
}	t_command;

// node of the stack
typedef struct s_node
{
	int				data;
	int				index;
	t_command		command;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// stack structure
typedef struct s_stack
{
	t_node	*top;
}	t_stack;
// stack management functions
void		stack_init(t_stack *stack, t_stack *stack_b);
void		stack_index_init(t_stack *stack);
void		both_stack_index_init(t_stack *stack_a, t_stack *stack_b);
void		free_stack(t_stack *stack);
// stack check functions
bool		is_empty(t_stack *stack);
bool		is_sorted(t_stack *stack);
// stack get information functions
int			get_len_stack(t_stack *stack);
int			get_max_data(t_stack *stack);
int			get_min_data(t_stack *stack);
int			get_index_from_data(t_stack *stack, int data);
void		print_stack(t_stack *stack, char *name);
// push_swap (main) fanctions
void		push_swap(int len, t_stack *stack_a, t_stack *stack_b);
// stack operations
void		swap(t_stack *stack, char c);
void		rotate(t_stack *stack, char c);
void		reverse_rotate(t_stack *stack, char c);
bool		push(t_stack *stack, int data);
bool		push_to(t_stack *stack_a, t_stack *stack_b, char c);
// command functions
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);
bool		pa(t_stack *stack_a, t_stack *stack_b);
bool		pb(t_stack *stack_a, t_stack *stack_b);
// error functions
void		error_print(void);
void		error_print_exit(void);
void		malloc_error_print(void);
// utility functions
int			push_swap_atoi(char *str); // atoi with error check
int			ft_abs(int nbr);
// sort functions
void		sort_len_3(t_stack *stack);
bool		sort(t_stack *stack_a, t_stack *stack_b);
int			get_target_from_b(t_stack *stack_b, int data);
int			get_target_from_a(t_stack *stack_a, int data);
// command utils functions
t_command	calculation_command(int a_index, int b_index, int a_len, int b_len);
void		do_command(t_command command, t_stack *stack_a, t_stack *stack_b);
t_command	command_init(void);
// command utils2 functions
void		commnad_set_rarb(t_command *command, int ra_count, int rb_count);
void		commnad_set_rrarrb(t_command *command,
				int rra_count,
				int rrb_count);
void		command_set_rarrb(t_command *command, int ra_count, int rb_count);
void		command_set_rrarb(t_command *command, int rra_count, int rb_count);
// command utils3 functions
void		register_command_push_a(t_stack *stack_a,
				t_stack *stack_b,
				int b_data,
				t_command *command);
void		register_command_push_b(t_stack *stack_a,
				t_stack *stack_b,
				int a_data,
				t_command *command);
t_command	*serch_optimal_command_push_to_a(t_stack *stack_a,
				t_stack *stack_b);
t_command	*serch_optimal_command_push_to_b(t_stack *stack_a,
				t_stack *stack_b);

#endif
