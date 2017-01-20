#include "monty.h"

/**
 * add_to_stack - adds the node to the beginning of the stack
 * @head: head of the stack
 * @n: number value for the stack
 * Return: 1 if success and 0 if fail
 */

int add_to_stack(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (-1);
	new_node->n = n;
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
	return (0);
}

/**
 * free_stack - frees the stack
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * delete_stack_head - deletes the head node of the stack
 * @head: head of the stack
 * Return: 1 if true, -1 if false
 */

int delete_stack_head(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return (-1);
	temp = (*head);
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
	return (1);
}

/**
 * delete_stack_end - deletes the end of the stack
 * @head: head of the stack
 */

int delete_stack_end(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return (-1);
	temp = *head;
	while (temp != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
	return (1);
}

/**
 * print_stack - prints the stack
 * @head: head of the stack
 */

void print_stack(stack_t **head)
{
	stack_t *temp;

	temp = (*head);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
