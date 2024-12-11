import struct
import sys
import os

class ArchitectureDecoder:
    def __init__(self, source_arch='32bit', target_arch='64bit'):
        """
        Initialize decoder for cross-architecture file parsing
        
        Args:
        - source_arch (str): Architecture of the original file ('32bit' or '64bit')
        - target_arch (str): Current system's architecture ('32bit' or '64bit')
        """
        self.source_arch = source_arch
        self.target_arch = target_arch
    
    def _get_type_sizes(self):
        """
        Define type sizes for different architectures
        
        Returns:
        - dict: Mapping of type names to their sizes in bytes
        """
        return {
            '32bit': {
                'int': 4,
                'long': 4,
                'pointer': 4,
                'size_t': 4
            },
            '64bit': {
                'int': 4,
                'long': 8,
                'pointer': 8,
                'size_t': 8
            }
        }
    
    def read_file(self, filename, data_type='int', endian='little'):
        """
        Read file with architecture-aware parsing
        
        Args:
        - filename (str): Path to the file
        - data_type (str): Type to parse ('int', 'long', 'pointer', 'size_t')
        - endian (str): Endianness ('little' or 'big')
        
        Returns:
        - list: Parsed values potentially adjusted for architecture
        """
        # Determine endian prefix
        endian_prefix = '<' if endian == 'little' else '>'
        
        # Get type sizes
        sizes = self._get_type_sizes()
        
        # Determine format string based on source architecture
        source_size = sizes[self.source_arch][data_type]
        target_size = sizes[self.target_arch][data_type]

        # Choose appropriate format character
        format_chars = {
            4: 'I',  # unsigned int
            8: 'Q'   # unsigned long long
        }
        
        source_format = endian_prefix + format_chars.get(source_size, 'I')
        target_format = endian_prefix + format_chars.get(target_size, 'Q')
        
        values = []
        with open(filename, 'rb') as f:
            while True:
                # Read chunk based on source architecture's type size
                chunk = f.read(source_size)
                if not chunk:
                    break
                
                try:
                    # Unpack from source format
                    source_value = struct.unpack(source_format, chunk)[0]
                    
                    # Convert if architectures differ
                    if self.source_arch != self.target_arch:
                        # Pack and unpack to convert
                        converted = struct.unpack(target_format, 
                                     struct.pack(source_format, source_value))[0]
                        values.append(converted)
                    else:
                        values.append(source_value)
                    
                except struct.error as e:
                    print(f"struct.error: {e}")
                    raise e
        
        return values
    
    def detect_system_architecture(self):
        """
        Detect current system's architecture
        
        Returns:
        - str: '32bit' or '64bit'
        """
        return '64bit' if sys.maxsize > 2**32 else '32bit'
    
    def print_diagnostic_info(self, filename):
        """
        Print diagnostic information about file and architectures
        
        Args:
        - filename (str): Path to the file
        """
        print(f"Source Architecture: {self.source_arch}")
        print(f"Current System Architecture: {self.target_arch}")
        print(f"Current Python Architecture: {self.detect_system_architecture()}")

        if self.target_arch is None:
            self.target_arch = self.detect_system_architecture()
        
        # Try reading with different types
        types_to_try = ['int', 'long', 'pointer', 'size_t']
        
        print("\nTrying different type parsings:")
        for type_name in types_to_try:
            try:
                values = self.read_file(filename, data_type=type_name)
                print(f"{type_name.capitalize()} values: {values}")
            except Exception as e:
                print(f"Error parsing {type_name}: {e}")


def read_file_endian(filename, endian='little', data_type='I'):
    """
    Read a file with a specified endian format and data type.
    
    Args:
    - filename (str): Path to the file to read
    - endian (str): Endian format - 'little' or 'big'
    - data_type (str): Struct format character 
        'I' - unsigned int (4 bytes)
        'H' - unsigned short (2 bytes)
        'Q' - unsigned long long (8 bytes)
        'i' - signed int
        'f' - float
        etc.
    
    Returns:
    - list: Parsed values from the file
    """
    # Determine endian prefix
    endian_prefix = '<' if endian == 'little' else '>'
    format_string = endian_prefix + data_type

    values = []
    with open(filename, 'rb') as f:
        while True:
            # Read one chunk based on the data type size
            chunk = f.read(struct.calcsize(format_string))
            if not chunk:
                break
            
            try:
                values.append(struct.unpack(format_string, chunk)[0])
            except struct.error:
                break
    
    return values


def convert_endian(value, from_endian='little', to_endian='big', data_type='I'):
    """
    Convert a single value between endian formats.
    
    Args:
    - value (int/float): Value to convert
    - from_endian (str): Source endian format
    - to_endian (str): Target endian format
    - data_type (str): Struct format character
    
    Returns:
    - Converted value
    """
    # Pack in source endian, unpack in target endian
    from_prefix = '<' if from_endian == 'little' else '>'
    to_prefix = '<' if to_endian == 'little' else '>'
    
    packed = struct.pack(from_prefix + data_type, value)
    return struct.unpack(to_prefix + data_type, packed)[0]

def hex_view(values, bytes_per_line=16):
    """
    Create a hex view of the parsed values.
    
    Args:
    - values (list): List of parsed values
    - bytes_per_line (int): Number of bytes to show per line
    
    Returns:
    - str: Formatted hex representation
    """
    hex_output = []
    for value in values:
        # Convert value to hex, remove '0x' prefix, pad to ensure even length
        hex_str = f'{value:x}'.zfill(2)  # Assuming 4-byte values
        hex_output.append(hex_str)
    
    return ' '.join(hex_output)


def main():
    # Replace with your actual filename
    filename = 'mystery'
    
    # Try reading with different endians and data types
    endian_combinations = [
        ('little', 'I'),  # unsigned int
        ('big', 'I'),
        ('little', 'H'),  # unsigned short
        ('big', 'H')
    ]
    
    # for endian, data_type in endian_combinations:
    #     print(f"Reading with {endian} endian, type {data_type}:")
    #     try:
    #         print(hex_view(read_file_endian(filename, endian, data_type)))
    #     except Exception as e:
    #         print(f"Error: {e}")

    # Auto-detect current system architecture
    decoder = ArchitectureDecoder(
        source_arch='32bit',  # Specify the source system's architecture
        target_arch=None  # Will auto-detect
    )
    
    # Print diagnostic information
    decoder.print_diagnostic_info(filename)


if __name__ == '__main__':
    main()

