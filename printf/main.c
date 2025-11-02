/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:06:09 by aprivalo          #+#    #+#             */
/*   Updated: 2025/11/02 22:18:36 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>  // pour le vrai printf

int	main(void)
{
	int ret_ft;
	int ret_std;
	int number = 42;
	int neg = -42;
	char c = 'A';
	char *str = "Hello world";
	void *ptr = &number;

	printf("===========================================\n");
	printf("🧪 TEST COMPARATIF ft_printf vs printf\n");
	printf("===========================================\n\n");

	// 🔹 Test 1 : simple texte
	printf("Test 1 : texte simple\n");
	ret_ft = ft_printf("FT : Salut !\n");
	ret_std = printf("STD: Salut !\n");
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	// 🔹 Test 2 : %c
	printf("Test 2 : %%c\n");
	ret_ft = ft_printf("FT : caractère = [%c]\n", c);
	ret_std = printf("STD: caractère = [%c]\n", c);
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	// 🔹 Test 3 : %s
	printf("Test 3 : %%s\n");
	ret_ft = ft_printf("FT : chaîne = [%s]\n", str);
	ret_std = printf("STD: chaîne = [%s]\n", str);
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	// 🔹 Test 4 : %d / %i
	printf("Test 4 : %%d / %%i\n");
	ret_ft = ft_printf("FT : nombre = [%d] / [%i]\n", number, neg);
	ret_std = printf("STD: nombre = [%d] / [%i]\n", number, neg);
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	// 🔹 Test 5 : %p
	printf("Test 5 : %%p\n");
	ret_ft = ft_printf("FT : pointeur = [%p]\n", ptr);
	ret_std = printf("STD: pointeur = [%p]\n", ptr);
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	// 🔹 Test 6 : mélange complet
	printf("Test 6 : mix complet\n");
	ret_ft = ft_printf("FT : [%s] %c %d %p %i\n", str, c, number, ptr, neg);
	ret_std = printf("STD: [%s] %c %d %p %i\n", str, c, number, ptr, neg);
	printf("Résultat attendu = %d | Résultat ft_printf = %d\n\n", ret_std, ret_ft);

	printf("===========================================\n");
	printf("✅ Fin du test comparatif\n");
	printf("===========================================\n");

	return (0);
}
