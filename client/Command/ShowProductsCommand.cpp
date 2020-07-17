#include "ShowProductsCommand.h"
#include "../Client.h"
#include <vector>

ShowProductsCommand::ShowProductsCommand(std::vector<int> products):
                        Command(0, 0), products(products) {}

void ShowProductsCommand::execute(Client& client){
    client.showProducts(products);
}
