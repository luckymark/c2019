import torch
import torch.optim as optim
from model import *
import os
import matplotlib.pyplot as plt

learning_rate = 1e-3
num_iter = 10000


# make some random data for sanity check
def make_data():
    x_data = torch.rand(num_iter, 8 * 8)
    y_data = torch.randint(0, 10, (num_iter, 1))
    return x_data, y_data


def train(data_x, data_y):
    model = TwoLayerNN(8 * 8, 32, 10)
    criterion = torch.nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=learning_rate)
    if os.path.exists('model.pth'):
        print('Load pre-trained model...')
        model.load_state_dict(torch.load('model.pth'))
        print('Done!')

    print('Start training...')
    loss_his = []
    for i in range(num_iter):
        out = model(data_x[i].view(1, -1))
        loss = criterion(out, y[i])
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()
        if i % 100 == 0:
            loss_his.append(loss.item())
        if i % 1000 == 0:
            print('Step: {}, Loss: {}'.format(i, loss.item()))
    print('Finished training!')

    # save model
    torch.save(model.state_dict(), 'model.pth')
    plt.figure('Loss history')
    plt.xlabel('Step')
    plt.ylabel('Loss')
    plt.plot(loss_his)
    plt.show()


if __name__ == '__main__':
    # replace make_data with real data in practice!
    x, y = make_data()
    train(x, y)
