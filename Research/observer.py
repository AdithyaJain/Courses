import math


class Observer:
    def __init__(self, oid, position):
        self.oid = oid
        self.position = position
        self.destination = position
        self.target_list = []
        self.lstp = None

    def get_position(self):
        return self.position

    def set_position(self, position):
        self.position = position

    def get_destination(self):
        return self.destination

    def set_destination(self, destination):
        self.destination = destination

    def move(self):
        position = self.position
        destination = self.destination
        if position != destination:
            direction_vector = (destination[0] - position[0], destination[1] - position[1])
            magnitude_direction = math.sqrt(direction_vector[0] ** 2 + direction_vector[1] ** 2)
            unit_direction_vector = [i/magnitude_direction for i in direction_vector]

            if magnitude_direction < 1:
                self.position = destination
            else:
                self.set_position((position[0] + unit_direction_vector[0], position[1] + unit_direction_vector[1]))