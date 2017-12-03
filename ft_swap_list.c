#include  <stdlib.h>
#include  "ft_list.h"

void    ft_swap_ptr(t_list **ptr1, t_list **ptr2)
{
    t_list  *temp_ptr;

    temp_ptr = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp_ptr;
}

void    ft_swap_list(t_list **begin_list,
                        t_list **list1,
                        t_list **list2,
                        t_list *prev_list1,   /* previous element of list1 */
                        t_list *prev_list2)   /* previous element of list2 */
{
    t_list  *temp_next;

    temp_next = (*list2)->next;

    /* if list1 is not the first element of the list */
    if (prev_list1 != NULL)
        prev_list1->next = (*list2);

    else
        (*begin_list) = (*list2);

    /* if list2 is not directly next to list1 */
    if (prev_list2 != (*list1))
    {   
        (*list2)->next = (*list1)->next;
        prev_list2->next = (*list1);
    }   

    else
        (*list2)->next = (*list1);

    (*list1)->next = temp_next;

    ft_swap_ptr(list1, list2);
}
