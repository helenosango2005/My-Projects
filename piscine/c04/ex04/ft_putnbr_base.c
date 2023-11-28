/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsango <hsango@student.42luanda.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:28:36 by hsango            #+#    #+#             */
/*   Updated: 2023/11/28 13:29:50 by hsango           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int is_valid_base(char *base) {
    if (!base || base[0] == '\0' || base[1] == '\0') {
        return 0;  // Base vazia ou de tamanho 1
    }

    int i = 0;
    while (base[i] != '\0') {
        if (base[i] == '+' || base[i] == '-') {
            return 0;  // Base contém '+' ou '-'
        }

        int j = i + 1;
        while (base[j] != '\0') {
            if (base[i] == base[j]) {
                return 0;  // Base contém dois caracteres iguais
            }
            j++;
        }
        i++;
    }

    return 1;  // Base válida
}

int get_base_length(char *base) {
    int length = 0;
    while (base[length] != '\0') {
        length++;
    }
    return length;
}

void ft_putnbr_base_recursive(int nbr, char *base, int base_length) {
    if (nbr < 0) {
        write(1, "-", 1);
        nbr = -nbr;
    }

    if (nbr >= base_length) {
        ft_putnbr_base_recursive(nbr / base_length, base, base_length);
    }

    char digit = base[nbr % base_length];
    write(1, &digit, 1);
}

void ft_putnbr_base(int nbr, char *base) {
    if (!is_valid_base(base)) {
        return;  // Base inválida, não faz nada
    }

    int base_length = get_base_length(base);

    ft_putnbr_base_recursive(nbr, base, base_length);
}

// Exemplo de uso:
int main() {
    ft_putnbr_base(42, "0123456789");  // Imprime "42" em decimal
    ft_putnbr_base(42, "01");          // Imprime "101010" em binário
    ft_putnbr_base(42, "0123456789ABCDEF");  // Imprime "2A" em hexadecimal
    ft_putnbr_base(42, "poneyvif");           // Imprime "56" em octal

    return 0;
}
