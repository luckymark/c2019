import torch
import torch.nn as nn
import torch.nn.functional as F


class TwoLayerNN(nn.Module):
    def __init__(self, input_dim, hidden_dim, num_classes):
        super(TwoLayerNN, self).__init__()
        self.fc1 = nn.Linear(input_dim, hidden_dim)
        self.fc2 = nn.Linear(hidden_dim, num_classes)

    def forward(self, x):
        out = self.fc1(x)
        out = F.relu(out)
        out = self.fc2(out)
        out = F.softmax(out, dim=1)
        return out
