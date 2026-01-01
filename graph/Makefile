# ==================== 配置区域 ====================
CXX = g++
CXXSTD = -std=c++11
CXXFLAGS = $(CXXSTD) -Wall -Wextra -pedantic -I./include
DEBUGFLAGS = -g -O0 -DDEBUG
RELEASEFLAGS = -O3 -DNDEBUG

# 目录设置
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# 主文件
PRIM_MAIN = prim_main.cpp
KRUSKAL_MAIN = kruskal_main.cpp
DIJKSTRA_MAIN = dijkstra_main.cpp
HO_DIJKSTRA_MAIN = ho_dijkstra_main.cpp
BELLMAN_FORD_MAIN = bellman_ford_main.cpp
QO_BELLMAN_FORD_MAIN = qo_bellman_ford_main.cpp  # 新增

# 目标文件
PRIM_OBJS = $(OBJ_DIR)/prim.o
KRUSKAL_OBJS = $(OBJ_DIR)/kruskal.o $(OBJ_DIR)/union-find.o
DIJKSTRA_OBJS = $(OBJ_DIR)/dijkstra.o
HO_DIJKSTRA_OBJS = $(OBJ_DIR)/ho_dijkstra.o
BELLMAN_FORD_OBJS = $(OBJ_DIR)/bellman_ford.o
QO_BELLMAN_FORD_OBJS = $(OBJ_DIR)/qo_bellman_ford.o  # 新增

# 可执行文件
TARGETS = $(BIN_DIR)/prim $(BIN_DIR)/kruskal $(BIN_DIR)/dijkstra \
          $(BIN_DIR)/ho_dijkstra $(BIN_DIR)/bellman_ford \
          $(BIN_DIR)/qo_bellman_ford  # 新增

# ==================== 构建规则 ====================
# 默认构建所有目标
all: CXXFLAGS += $(DEBUGFLAGS)
all: $(TARGETS)

# 发布构建
release: CXXFLAGS += $(RELEASEFLAGS)
release: $(TARGETS)

# 单独构建
prim: $(BIN_DIR)/prim
kruskal: $(BIN_DIR)/kruskal
dijkstra: $(BIN_DIR)/dijkstra
ho_dijkstra: $(BIN_DIR)/ho_dijkstra
bellman_ford: $(BIN_DIR)/bellman_ford
qo_bellman_ford: $(BIN_DIR)/qo_bellman_ford  # 新增

# Prim 可执行文件
$(BIN_DIR)/prim: $(PRIM_MAIN) $(PRIM_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(PRIM_OBJS)

# Kruskal 可执行文件
$(BIN_DIR)/kruskal: $(KRUSKAL_MAIN) $(KRUSKAL_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(KRUSKAL_OBJS)

# Dijkstra 可执行文件
$(BIN_DIR)/dijkstra: $(DIJKSTRA_MAIN) $(DIJKSTRA_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(DIJKSTRA_OBJS)

# HO Dijkstra 可执行文件
$(BIN_DIR)/ho_dijkstra: $(HO_DIJKSTRA_MAIN) $(HO_DIJKSTRA_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(HO_DIJKSTRA_OBJS)

# Bellman-Ford 可执行文件
$(BIN_DIR)/bellman_ford: $(BELLMAN_FORD_MAIN) $(BELLMAN_FORD_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(BELLMAN_FORD_OBJS)

# Queue-Optimized Bellman-Ford 可执行文件（新增）
$(BIN_DIR)/qo_bellman_ford: $(QO_BELLMAN_FORD_MAIN) $(QO_BELLMAN_FORD_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $< $(QO_BELLMAN_FORD_OBJS)

# 编译 src 目录下的源文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建目录
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 清理
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# 运行测试
run-prim: $(BIN_DIR)/prim
	@echo "=== Running Prim's Algorithm ==="
	@./$(BIN_DIR)/prim
	@echo "✓ Prim: 最小生成树算法 (适合稠密图)" && echo

run-kruskal: $(BIN_DIR)/kruskal
	@echo "=== Running Kruskal's Algorithm ==="
	@./$(BIN_DIR)/kruskal
	@echo "✓ Kruskal: 最小生成树算法 (适合稀疏图，使用并查集)" && echo

run-dijkstra: $(BIN_DIR)/dijkstra
	@echo "=== Running Dijkstra's Algorithm ==="
	@./$(BIN_DIR)/dijkstra
	@echo "✓ Dijkstra: 单源最短路径 (无负权边)" && echo

run-ho-dijkstra: $(BIN_DIR)/ho_dijkstra
	@echo "=== Running Heap-Optimized Dijkstra's Algorithm ==="
	@./$(BIN_DIR)/ho_dijkstra
	@echo "✓ Heap-Optimized Dijkstra: 堆优化的 Dijkstra (更高效)" && echo

run-bellman-ford: $(BIN_DIR)/bellman_ford
	@echo "=== Running Bellman-Ford Algorithm ==="
	@./$(BIN_DIR)/bellman_ford
	@echo "✓ Bellman-Ford: 单源最短路径 (支持负权边，可检测负权环)" && echo

run-qo-bellman-ford: $(BIN_DIR)/qo_bellman_ford
	@echo "=== Running Queue-Optimized Bellman-Ford Algorithm ==="
	@./$(BIN_DIR)/qo_bellman_ford
	@echo "✓ Queue-Optimized Bellman-Ford: 队列优化的 Bellman-Ford (SPFA 算法)" && echo

# 运行所有算法
run-all: run-prim run-kruskal run-dijkstra run-ho-dijkstra run-bellman-ford run-qo-bellman-ford
	@echo "======================================"
	@echo "所有算法运行完成！总结："
	@echo "1. Prim: 最小生成树算法 (适合稠密图)"
	@echo "2. Kruskal: 最小生成树算法 (适合稀疏图，使用并查集)"
	@echo "3. Dijkstra: 单源最短路径 (无负权边)"
	@echo "4. Heap-Optimized Dijkstra: 堆优化的 Dijkstra (更高效)"
	@echo "5. Bellman-Ford: 单源最短路径 (支持负权边，可检测负权环)"
	@echo "6. Queue-Optimized Bellman-Ford: 队列优化的 Bellman-Ford (SPFA)"
	@echo "======================================"

.PHONY: all release prim kruskal dijkstra ho_dijkstra bellman_ford qo_bellman_ford clean \
        run-prim run-kruskal run-dijkstra run-ho-dijkstra run-bellman-ford run-qo-bellman-ford run-all

# 帮助信息
help:
	@echo "可用的 make 目标:"
	@echo "  all              - 编译所有算法 (调试模式)"
	@echo "  release         - 编译所有算法 (发布模式)"
	@echo "  clean           - 清理编译文件"
	@echo ""
	@echo "单独编译:"
	@echo "  prim            - 编译 Prim 算法"
	@echo "  kruskal         - 编译 Kruskal 算法"
	@echo "  dijkstra        - 编译 Dijkstra 算法"
	@echo "  ho_dijkstra     - 编译 Heap-Optimized Dijkstra"
	@echo "  bellman_ford    - 编译 Bellman-Ford 算法"
	@echo "  qo_bellman_ford - 编译 Queue-Optimized Bellman-Ford (SPFA)"
	@echo ""
	@echo "运行测试:"
	@echo "  run-prim        - 运行 Prim 算法"
	@echo "  run-kruskal     - 运行 Kruskal 算法"
	@echo "  run-dijkstra    - 运行 Dijkstra 算法"
	@echo "  run-ho-dijkstra - 运行 Heap-Optimized Dijkstra"
	@echo "  run-bellman-ford - 运行 Bellman-Ford 算法"
	@echo "  run-qo-bellman-ford - 运行 Queue-Optimized Bellman-Ford"
	@echo "  run-all         - 运行所有算法并显示总结"
	@echo ""
	@echo "当前支持的图算法:"
	@echo "  1. Prim: 最小生成树算法 (适合稠密图)"
	@echo "  2. Kruskal: 最小生成树算法 (适合稀疏图，使用并查集)"
	@echo "  3. Dijkstra: 单源最短路径 (无负权边)"
	@echo "  4. Heap-Optimized Dijkstra: 堆优化的 Dijkstra (更高效)"
	@echo "  5. Bellman-Ford: 单源最短路径 (支持负权边，可检测负权环)"
	@echo "  6. Queue-Optimized Bellman-Ford: 队列优化的 Bellman-Ford (SPFA)"
	@echo ""
	@echo "项目结构:"
	@echo "  include/     - 头文件"
	@echo "  src/         - 源文件"
	@echo "  *.cpp        - 主程序文件"
	@echo "  bin/         - 可执行文件"
	@echo "  obj/         - 目标文件"

.PHONY: help
