#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void print_error(MYSQL *conn) {
    fprintf(stderr, "Error: %s\n", mysql_error(conn));
}

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    // MySQL 초기화
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return EXIT_FAILURE;
    }

    // MySQL 서버에 연결
    if (mysql_real_connect(conn, "localhost", "root", "yourpassword", "school", 0, NULL, 0) == NULL) {
        print_error(conn);
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // 학생 정보 삽입
    const char *insert_query = "INSERT INTO students (name, age) VALUES ('John', 21)";
    if (mysql_query(conn, insert_query)) {
        print_error(conn);
    }

    // 학생 정보 조회
    if (mysql_query(conn, "SELECT * FROM students")) {
        print_error(conn);
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // 결과 처리
    res = mysql_store_result(conn);
    if (res == NULL) {
        print_error(conn);
        mysql_close(conn);
        return EXIT_FAILURE;
    }

    // 학생 정보 출력
    printf("ID\tName\t\tAge\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
    }

    // 메모리 해제
    mysql_free_result(res);
    mysql_close(conn);

    return EXIT_SUCCESS;
}
