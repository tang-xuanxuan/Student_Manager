# 可执行文件名
TARGET = manager
# 分离 C 和 C++ 源文件
CXX_SRCS = main.cpp student.cpp course.cpp course_manager.cpp student_manager.cpp score_manager.cpp manager.cpp database_manager.cpp
C_SRCS = sqlite3.c  # SQLite 是 C 代码
# 生成目标文件
CXX_OBJS = $(CXX_SRCS:.cpp=.o)
C_OBJS = $(C_SRCS:.c=.o)
OBJS = $(CXX_OBJS) $(C_OBJS)
# 编译器
CXX = g++
CC = gcc  # C 编译器
CXXFLAGS = -Wall -g
CFLAGS = -Wall -g  # C 编译选项

# 默认目标
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 编译 C++ 文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 编译 C 文件（单独规则）
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
clean:
	del /f $(OBJS) $(TARGET).exe