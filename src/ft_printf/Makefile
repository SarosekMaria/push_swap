# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:24:17 by sassassi          #+#    #+#              #
#    Updated: 2020/02/11 17:21:52 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@gcc -Wall -Wextra -Werror -c ft_printf.c ft_del.c ft_vspomog.c ft_left_alignment.c ft_right_alignment.c ft_exp.c ft_vspom4.c ft_define_format.c ft_buf_init_e.c ft_check_linfnan.c ft_check_infnan.c ft_ldouble_mantissa.c ft_double_mantissa.c ft_rounding_f.c ft_double_exp.c ft_division_str.c ft_pow.c ft_pow_str_2.c ft_pow_str_10.c ft_sum_str_frac.c ft_overflow_digit_check.c ft_help.c ft_parser.c ft_print_char.c ft_print_percent.c ft_print_string.c ft_bitwise_shift.c ft_bitwise_shift_buf.c ft_itoa_base.c ft_print_float.c ft_print_octal.c ft_print_hex.c ft_print_udecimal.c ft_print_decimal.c ft_print_pointer.c ft_buf_init_dioux.c ft_buf_init_float.c ft_buf_init_u.c ft_buf_init_o.c ft_buf_init_d.c ft_buf_init_x.c ft_itoa_u.c ft_itoa_s.c ft_if_hash.c ft_sum_str_int.c kostyliivelosipedy.c ft_buf_init_inff.c ft_help_2.c ft_print_binar.c libft/*.c -I libft/includes -g
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@mv *.o ./obj/

clean:
	@/bin/rm -f ./obj/*.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
