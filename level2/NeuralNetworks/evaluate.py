import torch
from model import *
import os

model = TwoLayerNN(8 * 8, 32, 10)
if os.path.exists('model.pth'):
    model.load_state_dict(torch.load('model.pth'))
else:
    raise Exception('No model found')


def make_data():
    return torch.rand(1, 8 * 8)


x_in = make_data()
out = model(x_in)
label = out.argmax(dim=1).item()
print('Predict label: {}'.format(label))
