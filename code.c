#include <stdio.h>

typedef struct
{
    // em = electricity meter
    // wm = water meter
    int room_no;
    int pre_em_value;
    int now_em_value;
    int pre_wm_value;
    int now_wm_value;
    float cal_e_bill;
    float cal_w_bill;
}data;

void Input_rooms(int n, data *room);
void cal_bill(int n, data *room);
void SortbyID(int n, data *room);
void Print_bill(int n, data *room);

int main()
{
    int n_room;
    printf("Input Number of rooms: ");
    scanf("%d", &n_room);
    printf("\n");
    data room[n_room];
    Input_rooms(n_room, room);
    cal_bill(n_room, room);
    SortbyID(n_room, room);
    Print_bill(n_room, room);
    return 0;
}

void Input_rooms(int n, data *room)
{
    for (int i=0; i<n; i++)
    {
        printf("Input room no: ");
        scanf("%d", &room[i].room_no);

        printf("Input Previous electricity meter values room %d: ", room[i].room_no);
        scanf("%d", &room[i].pre_em_value);
        printf("Input Current electricity meter values room %d: ", room[i].room_no);
        scanf("%d", &room[i].now_em_value);

        printf("Input Previous water meter values room %d: ", room[i].room_no);
        scanf("%d", &room[i].pre_wm_value);
        printf("Input Current water meter values room %d: ", room[i].room_no);
        scanf("%d", &room[i].now_wm_value);
        printf("\n");
    }
}

void cal_bill(int n, data *room)
{
    float e_unit, w_unit;
    printf("Electricity per unit: ");
    scanf("%f", &e_unit);
    printf("Water per unit: ");
    scanf("%f", &w_unit);
    printf("\n");

    for (int i=0; i<n; i++)
    {
        if (room[i].pre_em_value <= room[i].now_em_value)
        {
            room[i].cal_e_bill = (room[i].now_em_value-room[i].pre_em_value)*e_unit;
        }
        else
        {
            room[i].cal_e_bill = ((10000-room[i].pre_em_value)+room[i].now_em_value)*e_unit;
        }
    }

    for (int i=0; i<n; i++)
    {
        if (room[i].pre_wm_value <= room[i].now_wm_value)
        {
            room[i].cal_w_bill = (room[i].now_wm_value-room[i].pre_wm_value)*w_unit;
        }
        else
        {
            room[i].cal_w_bill = ((10000-room[i].pre_wm_value)+room[i].now_wm_value)*w_unit;
        }
    }

}

void SortbyID(int n, data *room)
{
    data temp;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (room[i].room_no > room[j].room_no)
            {
                temp = room[i];
                room[i] = room[j];
                room[j] = temp;
            }
        }
    }
}

void Print_bill(int n, data *room)
{
    for (int i=0; i<n; i++)
    {
        printf("room %d\n",room[i].room_no);
        printf("Electricity bill: %.2f\n",room[i].cal_e_bill);
        printf("Water bill: %.2f\n",room[i].cal_w_bill);
        printf("\n");
    }
}