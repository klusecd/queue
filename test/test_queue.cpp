#include "queue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(4));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-2));
}


TEST(TQueue, can_create_queue_with_max_size)
{
	ASSERT_NO_THROW(TQueue<int> q(MAX_SIZE));
}

TEST(TQueue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue<int> q(MAX_SIZE + 1));
}

TEST(TQueue, can_push)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, can_pop)
{
	TQueue<int> q(5);
	q.push(1);
	ASSERT_NO_THROW(q.pop());
}


TEST(TQueue, return_true_when_queue_is_empty) {
	TQueue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(TQueue, return_false_when_queue_isnt_empty) {
	TQueue<int> q(1);
	EXPECT_EQ(false, q.empty());
}

TEST(TQueue, return_true_when_queue_is_full) {
	TQueue<int> q;
	EXPECT_EQ(true, q.full());
}

TEST(TQueue, return_false_when_queue_isnt_full) {
	TQueue<int> q(10);
	q.push(1);
	EXPECT_EQ(false, q.full());
}
