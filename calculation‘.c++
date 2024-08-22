#include <iostream>
#include <vector>
#include <string>

double cal(const std::string& fun, const std::vector<double>& params) {
    //如果参数列表为空，指出异常
    if (params.empty()) {
        throw std::invalid_argument("Parameter list is empty");
    }
    //初始化结果为列表参数的第一个数字

    double result = params[0]; 
    //根据计算的类型执行不同的运算

    if (fun == "add") {
        //执行加法运算
        for (size_t i = 1; i < params.size(); ++i) {
            result += params[i];
        }
    } else if (fun == "minus") {
        //执行减法运算
        for (size_t i = 1; i < params.size(); ++i) {
            result -= params[i];
        }
    } else {
        //如果运算类型不是add或者minus则指出异常
        throw std::invalid_argument("Invalid operation");
    }
    return result;
}

int main() {
    try {
        //初始化数字列表
        std::vector<double> numbers = {10, 20, 30, 40};
        //调用计算器函数执行加法并输出结果 
        double sum = cal("add", numbers); 
        std::cout << "Sum: " << sum << std::endl; 
        
        //调用计算器函数执行剑法并输出结果
        double difference = cal("minus", numbers); 
        std::cout << "Difference: " << difference << std::endl; 
    } catch (const std::invalid_argument& e) {
        //捕获并输出异常信息
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}