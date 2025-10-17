# 可执行文件名
TARGET = manager
# 所有源文件（添加新增的 .cpp 文件，用空格分隔）
SRCS = main.cpp student.cpp course.cpp course_manager.cpp student_manager.cpp score_manager.cpp manager.cpp
# 生成的中间目标文件（.o 文件，自动推导）
OBJS = $(SRCS:.cpp=.o)
# 编译器和编译选项
CXX = g++
CXXFLAGS = -Wall -g  # -Wall 显示警告，-g 支持调试

# 默认目标：编译生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# 编译每个 .cpp 生成 .o 文件（自动规则，无需手动写）
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理中间文件和可执行文件（执行 make clean 时调用）
clean:
# rm -f $(OBJS) $(TARGET)  # Linux/macOS 系统使用此行
# Windows 系统使用此行（删除 .o 文件和 .exe 可执行文件）
	del /f $(OBJS) $(TARGET).exe