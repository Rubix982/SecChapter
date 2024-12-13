from scipy.io import loadmat

# Load the MATLAB file
data = loadmat('extracted_matlab.mat')

# Print the data structure
for key, value in data.items():
    print(f"{key}: {value}")
