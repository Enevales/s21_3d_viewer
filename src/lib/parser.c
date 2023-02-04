
#include "core.h"
int check_object_file(const char *filename, mesh *data) //пока без проверок, просто считает строки с v и f
{
    FILE    *file;
    char    ch;
    data->count_vertices=0;
    data->count_polygons=0;
    data->count_edges=0;

    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }
    
    char *line = NULL;
    size_t len = 0;
    
	while (getline(&line, &len, file) != -1){
		if (line[0] == 'v') data->count_vertices++;
        if (line[0] == 'f') data->count_polygons++;
	
	}
    
    free(line);
    fclose(file);
    return (0);
}

void    parse_one_vertex(FILE *file, mesh *data, parse_info *counters)
{
    int     i;
    vertex* array;
    float x, y, z;

    i = counters->current_vertex;
    array = data->vertices;
    fscanf(file, "%f %f %f", &array[i].x, &array[i].y, &array[i].z);
    counters->current_vertex++;
}

int     count_vertices_in_string(char *str)
{
    int i = 0;
    int flag_is_space = 0;
    int counter = 0;

    while (str[i])
    {
        if (str[i] == ' ')
            flag_is_space = 0;
        else
        {
            if (flag_is_space == 0)
                counter++;
            flag_is_space = 1;
        }
        i++;                
    }
    return (counter);
}

void    parse_vertices_from_string(char *str, int num, int *array)
{
    int         i = 0;
    int         j = 0;
    int         k = 0;
    char        temp[10];

    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        j = 0;
        while (str[i] && str[i] != ' ')
        {
            temp[j] = str[i];
            j++;
            i++;
        }
        temp[j] = '\0';
        array[k] = atoi(temp);
        k++;
        if (k > 1 && k < (num * 2 - 1))
        {
            array[k] = array[k - 1];
            k++;
        }
    }
    array[num * 2 - 1] = array[0];
}


void    parse_one_polygon(FILE *file, mesh *data, parse_info *counters)
{
    int     i = 0;
    char    *temp_str;
    char    ch;
    int*    array;
    int     num;

    temp_str = malloc(STRING_BUFFER); //если надо будет оптимизировать, можно объявлять переменную на стеке размером в Буфер
    if (NULL == temp_str)
        exit(1);
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
        temp_str[i++] = ch;
    temp_str[i] = '\0';
    num = count_vertices_in_string(temp_str);
    data->count_edges += num;
    // printf("inside parse_one_polygon, num: %d\n", num);
    array = malloc(sizeof(int) * num * 2);
    if (NULL == array)
        exit(1);
    parse_vertices_from_string(temp_str, num, array);
    data->polygons[counters->current_polygon].num_of_edges = num * 2;
    data->polygons[counters->current_polygon].vertices = array;
    counters->current_polygon++;
    free(temp_str);
}

void    initialize_data(mesh *data, parse_info *counters)
{
    counters->current_vertex = 0;
    counters->current_polygon = 0;

}

int    parser(const char* filename, mesh *data)
{
    char        ch;
    parse_info  counters;
    FILE        *file;

    if (check_object_file(filename, data) == -1)
        return (-1);
    if ((file = fopen(filename, "r")) == NULL)
    {
        printf("Cannot open file: %s\n", filename);
        exit(1);
    }

    initialize_data(data, &counters);
    data->vertices = malloc(sizeof(vertex) * data->count_vertices);
    if (NULL == data->vertices)
        exit(1);
    data->polygons = malloc(sizeof(polygon) * data->count_polygons);
    if (NULL == data->polygons)
        exit(1);
    while((ch = fgetc(file)) != EOF)
    {
        if (ch == 'v')
            parse_one_vertex(file, data, &counters);//парсит из строки 3 числа float
        if (ch == 'f')
            parse_one_polygon(file, data, &counters);//парсит из строки все целые числа до конца строки или до конца файла
    }
    fclose(file);
}


void    print_one_polygon(mesh *data, int n)//для дебага, удалить перед сдачей
{
    printf("polygon[%d]: ", n);
    for (int i = 0; i < data->polygons[n].num_of_edges; i++)
        printf(" %d", data->polygons[n].vertices[i]);
    printf("\n");
}

