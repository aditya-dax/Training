import React from 'react';
import 'bootstrap/dist/css/bootstrap.css';
import { useState, useEffect } from "react"
import axios from 'axios';

// const baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs'


const Forms = () => {
    const [title, setTitle] = useState('');
    const [description, setDescription] = useState('');
    const [author, setAuthor] = useState('');
    const [reading_time, setReadingTime] = useState('');
    const [blogDataSubmit, setBlogDataSubmit] = useState(false)

    let blogData = {
        title: '',
        description: '',
        author: '',
        reading_time: ''
    }


    const handleSubmit = (e) => {

        let baseURL = 'https://qghcujpqbvrdfszremfe.supabase.co/rest/v1/blogs'

        e.preventDefault()
        
        blogData.title = title
        blogData.description = description
        blogData.author = author
        blogData.reading_time = reading_time
        console.log(blogData)

        axios.post(baseURL, blogData, {
            headers: {
                'Authorization': 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM',
                'apikey': 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJzdXBhYmFzZSIsInJlZiI6InFnaGN1anBxYnZyZGZzenJlbWZlIiwicm9sZSI6ImFub24iLCJpYXQiOjE2NTgxMjk3NzcsImV4cCI6MTk3MzcwNTc3N30.LvOp9lASnuJAAwvg2VxFmnrVXuqZOM0KVngw8EKHQcM'
            }
        }).then((response) => {
            console.log("Sent", response)
            setBlogDataSubmit(true)
        });

    }

    return (
        <div>
            <p>Blog Form</p>
            <input
                type="text"
                name="title"
                placeholder="enter title"
                value={title}
                onChange={e => setTitle(e.target.value)}
            />
            <br></br>
            <input
                type="text"
                name="description"
                placeholder="enter description"
                value={description}
                onChange={e => setDescription(e.target.value)}
            />
            <br></br>
            <input
                type="text"
                name="author"
                placeholder="enter author"
                value={author}
                onChange={e => setAuthor(e.target.value)}
            />
            <br></br>
            <input
                type="number"
                name="reading_time"
                placeholder="enter reading time"
                value={reading_time}
                onChange={e => setReadingTime(e.target.value)}
            />
            <br></br>
            <button
                type="submit" onClick={handleSubmit}
            >
                Submit
            </button>
        </div>
    )
}

export default Forms