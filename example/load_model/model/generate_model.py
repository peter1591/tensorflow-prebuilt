import tensorflow as tf
import numpy as np

with tf.Session() as sess:
    input1 = tf.placeholder(name='input1', dtype=tf.int32, shape=[1,140])
    output = tf.argmax(name='output', input=input1, axis=1)
    print(sess.graph_def)
    for n in sess.graph_def.node:
        print("node name: %s" % n.name)
    tf.train.write_graph(sess.graph_def, './model', 'graph.pb', as_text=False)
