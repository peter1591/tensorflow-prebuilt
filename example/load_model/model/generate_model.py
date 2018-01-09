import tensorflow as tf
import numpy as np

with tf.Session() as sess:
    input1 = tf.placeholder(name='input1', dtype=tf.int32)
    input2 = tf.placeholder(name='input2', dtype=tf.float32)
    output = tf.add(tf.cast(input1, tf.float32), input2, name="output")
    tf.train.write_graph(sess.graph_def, './model', 'graph.pb', as_text=False)